#!/bin/bash
#################################################
#
GN_PRODUCT_LOCALES=${MTK_PRODUCT_LOCALES}
VALUE_LENGHT=90
echo ${GN_PRODUCT_LOCALES}
while true 
do
    #GN_PRODUCT_LOCALES_EX1
    if [ ${#GN_PRODUCT_LOCALES} -ge $VALUE_LENGHT ];then
        GN_PRODUCT_LOCALES_EX1=${GN_PRODUCT_LOCALES:0:$VALUE_LENGHT}
        GN_PRODUCT_LOCALES=${GN_PRODUCT_LOCALES:$VALUE_LENGHT}
        echo "GN_PRODUCT_LOCALES_EX1="${GN_PRODUCT_LOCALES_EX1}
        export GN_PRODUCT_LOCALES_EX1
    else
        GN_PRODUCT_LOCALES_EX1=${GN_PRODUCT_LOCALES}
        echo "GN_PRODUCT_LOCALES_EX1="${GN_PRODUCT_LOCALES_EX1}
        export GN_PRODUCT_LOCALES_EX1
        break
    fi

    #GN_PRODUCT_LOCALES_EX2
    if [ ${#GN_PRODUCT_LOCALES} -ge $VALUE_LENGHT ];then
        GN_PRODUCT_LOCALES_EX2=${GN_PRODUCT_LOCALES:0:$VALUE_LENGHT}
        GN_PRODUCT_LOCALES=${GN_PRODUCT_LOCALES:$VALUE_LENGHT}
        echo "GN_PRODUCT_LOCALES_EX2="${GN_PRODUCT_LOCALES_EX2}
        export GN_PRODUCT_LOCALES_EX2
    else
        GN_PRODUCT_LOCALES_EX2=${GN_PRODUCT_LOCALES}
        echo "GN_PRODUCT_LOCALES_EX2="${GN_PRODUCT_LOCALES_EX2}
        export GN_PRODUCT_LOCALES_EX2
        break
    fi

    #GN_PRODUCT_LOCALES_EX3
    if [ ${#GN_PRODUCT_LOCALES} -ge $VALUE_LENGHT ];then
        GN_PRODUCT_LOCALES_EX3=${GN_PRODUCT_LOCALES:0:$VALUE_LENGHT}
        GN_PRODUCT_LOCALES=${GN_PRODUCT_LOCALES:$VALUE_LENGHT}
        echo "GN_PRODUCT_LOCALES_EX3="${GN_PRODUCT_LOCALES_EX3}
        export GN_PRODUCT_LOCALES_EX3
    else
        GN_PRODUCT_LOCALES_EX3=${GN_PRODUCT_LOCALES}
        echo "GN_PRODUCT_LOCALES_EX3="${GN_PRODUCT_LOCALES_EX3}
        export GN_PRODUCT_LOCALES_EX3
        break
    fi

    #GN_PRODUCT_LOCALES_EX4
    if [ ${#GN_PRODUCT_LOCALES} -ge $VALUE_LENGHT ];then
        GN_PRODUCT_LOCALES_EX4=${GN_PRODUCT_LOCALES:0:$VALUE_LENGHT}
        GN_PRODUCT_LOCALES=${GN_PRODUCT_LOCALES:$VALUE_LENGHT}
        echo "GN_PRODUCT_LOCALES_EX4="${GN_PRODUCT_LOCALES_EX4}
        export GN_PRODUCT_LOCALES_EX4
    else
        GN_PRODUCT_LOCALES_EX4=${GN_PRODUCT_LOCALES}
        echo "GN_PRODUCT_LOCALES_EX4="${GN_PRODUCT_LOCALES_EX4}
        export GN_PRODUCT_LOCALES_EX4
        break
    fi

    #GN_PRODUCT_LOCALES_EX5
    if [ ${#GN_PRODUCT_LOCALES} -ge $VALUE_LENGHT ];then
        GN_PRODUCT_LOCALES_EX5=${GN_PRODUCT_LOCALES:0:$VALUE_LENGHT}
        GN_PRODUCT_LOCALES=${GN_PRODUCT_LOCALES:$VALUE_LENGHT}
        echo "GN_PRODUCT_LOCALES_EX5="${GN_PRODUCT_LOCALES_EX5}
        export GN_PRODUCT_LOCALES_EX5
    else
        GN_PRODUCT_LOCALES_EX5=${GN_PRODUCT_LOCALES}
        echo "GN_PRODUCT_LOCALES_EX5="${GN_PRODUCT_LOCALES_EX5}
        export GN_PRODUCT_LOCALES_EX5
        break
    fi
done
	


