function extract_size_info (data) {
    if(data ~ _size) 
	print data
}

function extract_partition_info (data) {
    print data
}

BEGIN {
    _disk="Disk"
    _size="GB"
    _partition="/dev"
    print "                         Disk Statistics                            "
    print "********************************************************************"
    print "                                                                    "
}
{

    if($0 ~ _disk)
	extract_size_info($0)

    else if($0 ~ _partition)
	extract_partition_info($0)
}
