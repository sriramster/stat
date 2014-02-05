BEGIN {
    _hname=""
    _type=""
    _os_ver=""
    _os="" 
    _arch=""
    print "                         System Statistics                          "
    print "********************************************************************"
    print "                                                                     "
}
{
    if($0) {
	_hname = $2
	_os    = $1
	_os_ver = $6 " " $7 " " $3
	_arch   = $9
	print "Hostname :",_hname
	print "Operation System :",_os
	print "Version : ",_os_ver
	print "Arch :",_arch
    }
}
