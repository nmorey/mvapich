#! /bin/sh
##
## Copyright (C) by Argonne National Laboratory
##     See COPYRIGHT in top-level directory
##

cfile="src/mpi/coll/src/csel_json_autogen.c"

create_json_buf()
{
    json_file=$1
    bufname=$2

    echo "const char $bufname[] = {" >> $cfile

    # split all the characters in the json file into a character array
    cat ${json_file} | awk '{ printf("%s ", $0); }' | \
        sed -e "s/[[:space:]]//g" -e "s/\(.\)/'\1',/g" >> $cfile
    echo "0 };" >> $cfile
    echo >> $cfile
}

rm -f $cfile
cat > $cfile<<EOF
/*
 * Copyright (C) by Argonne National Laboratory
 *     See COPYRIGHT in top-level directory
 */

/* DO NOT EDIT!  This file is autogenerated from the corresponding
 * json files */

EOF

# create specific json buffers
create_json_buf maint/tuning/coll/mpir/mvp_generic.json MPII_coll_generic_json
create_json_buf maint/tuning/coll/ch4/generic.json MPIDI_coll_generic_json
create_json_buf maint/tuning/coll/ch4/posix_generic.json MPIDI_POSIX_coll_generic_json
