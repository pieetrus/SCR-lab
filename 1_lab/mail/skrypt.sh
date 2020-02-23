#skrypt do wysylania maili

#!/bin/bash

temat="Oferta zakupu"
tresc="tresc.txt"

while read adres
do
    
    mutt -e "set crypt_use_gpgme=no" -s "$temat" "$adres" -a spec*.pdf < "$tresc"
    echo wyslano maila na adres $adres
done < adresy.txt
