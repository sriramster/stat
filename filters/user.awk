BEGIN {
    _magic="499"
    print "                         System Statistics                          "
    print "********************************************************************"
    print "                                                                     "
}
{
    if ($3 <= _magic)
	print "system", $1 ,$6
    else
	print "user", $1 ,$6

}
