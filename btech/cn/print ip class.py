def printClass(ip):
    if ip[0]=='0':
        return "A"
    else: #ip[0]==1
        if ip[1]=='0':
            return "B"
        else: #ip[1]==1
            if ip[2]=='0':
                return "C"
            else: #ip[2]==1
                if ip[3]=='0':
                    return "D"
                else: #ip[3]==1
                    return "E"
                        

ip = "11110011 10011011 11111011 00001111"
print(printClass(ip))
