awk '{for(i=1;i<=NF;i++){if(s[i]){s[i]=s[i]" "$i;}else{s[i]=$i;}}} END{for(i in s){print s[i]}}' file.txt
