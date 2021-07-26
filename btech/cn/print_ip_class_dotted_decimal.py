#TCP/IP Protocol Suite by B Forouzan
# Chapter - 5 IPV4 ADDRESSES
# Example - 5.11

# return class of ip address if ipv4
# in dotted decimal is sent to the function
def printClass(ip):
    a1 = ip.split('.')
    f1 = int(a1[0])
    if f1<=127:
        return "A"
    elif f1<=191:
        return "B"
    elif f1<=223:
        return "C"
    elif f1<=239:
        return "D"
    elif f1<=255:
        return "E"
    else:
        return "Invalid IP address"
    

ip = ["227.12.14.87","193.14.56.22","14.23.120.8","252.5.15.111"]

for x in ip:
    print(x+" : "+printClass(x))
