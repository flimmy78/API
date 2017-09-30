#ifndef _NF_CONNTRACK_TIMEOUT_H
#define _NF_CONNTRACK_TIMEOUT_H

#include <net/net_namespace.h>
#include <linux/netfilter/nf_conntrack_common.h>
#include <linux/netfilter/nf_conntrack_tuple_common.h>
#include <linux/refcount.h>
#include <net/netfilter/nf_conntrack.h>
#include <net/netfilter/nf_conntrack_extend.h>

#define CTNL_TIMEOUT_NAME_MAX	32

struct ctnl_timeout {
	struct list_head	head;
	struct rcu_head		rcu_head;
	refcount_t		refcnt;
	char			name[CTNL_TIMEOUT_NAME_MAX];
	__u16			l3num;
	const struct nf_conntrack_l4proto *l4proto;
	char			data[0];
};

struct nf_conn_timeout {
	struct ctnl_timeout __rcu *timeout;
};

static inline unsigned int *
nf_ct_timeout_data(struct nf_conn_timeout *t)
{
	struct ctnl_timeout *timeout;

	timeout = rcu_dereference(t->timeout);
	if (timeout == NULL)
		return NULL;

	return (unsigned int *)timeout->data;
}

static inline
struct nf_conn_timeout *nf_ct_timeout_find(const struct nf_conn *ct)
{
#ifdef CONFIG_NF_CONNTRACK_TIMEOUT
	return nf_ct_ext_find(ct, NF_CT_EXT_TIMEOUT);
#else
	return NULL;
#endif
}

static inline
struct nf_conn_timeout *nf_ct_timeout_ext_add(struct nf_conn *ct,
					      struct ctnl_timeout *timeout,
					      gfp_t gfp)
{
#ifdef CONFIG_NF_CONNTRACK_TIMEOUT
	struct nf_conn_timeout *timeout_ext;

	timeout_ext = nf_ct_ext_add(ct, NF_CT_EXT_TIMEOUT, gfp);
	if (timeout_ext == NULL)
		return NULL;

	rcu_assign_pointer(timeout_ext->timeout, timeout);

	return timeout_ext;
#else
	return NULL;
#endif
};

static inline unsigned int *
nf_ct_timeout_lookup(struct net *net, struct nf_conn *ct,
		     const struct nf_conntrack_l4proto *l4proto)
{
#ifdef CONFIG_NF_CONNTRACK_TIMEOUT
	struct nf_conn_timeout *timeout_ext;
	unsigned int *timeouts;

	timeout_ext = nf_ct_timeout_find(ct);
	if (timeout_ext) {
		timeouts = nf_ct_timeout_data(timeout_ext);
		if (unlikely(!timeouts))
			timeouts = l4proto->get_timeouts(net);
	} else {
		timeouts = l4proto->get_timeouts(net);
	}

	return timeouts;
#else
	return l4proto->get_timeouts(net);
#endif
}

#ifdef CONFIG_NF_CONNTRACK_TIMEOUT
int nf_conntrack_timeout_init(void);
void nf_conntrack_timeout_fini(void);
#else
static inline int nf_conntrack_timeout_init(void)
{
        return 0;
}

static inline void nf_conntrack_timeout_fini(void)
{
        return;
}
#endif /* CONFIG_NF_CONNTRACK_TIMEOUT */

#ifdef CONFIG_NF_CONNTRACK_TIMEOUT
extern struct ctnl_timeout *(*nf_ct_timeout_find_get_hook)(struct net *net, const char *name);
extern void (*nf_ct_timeout_put_hook)(struct ctnl_timeout *timeout);
#endif

#endif /* _NF_CONNTRACK_TIMEOUT_H */
