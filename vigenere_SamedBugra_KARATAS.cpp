#include<stdio.h>
#include<string.h>

int main(){
    char msg[] = "SAMEDBUGRAKARATAS"; 								/* þifrelenecek metni dizide tutuyoruz  */
    char key[] = "MERHABA";											/* Anahtar kelimeyi dizide tutuyoruz  */
    int msgLen = strlen(msg), keyLen = strlen(key), i, j;			/* metnin ve anahtarýn uzunluðunu deðiþkenlere atýyoruz  */
 
    char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen]; /* metnin uzunluðunu(boyutunu) 3 farklý dizide tutuyoruz  */
 
    //generating new key
    for(i=0, j=0; i<msgLen; ++i, ++j)							/*   */
	{
        if(j == keyLen)
            j = 0;
 
        newKey[i] = key[j];
    }
 	newKey[i] = '\0';
 
 
 
 
    //þifreleme
    for(i=0; i<msgLen; ++i)
        encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';
    encryptedMsg[i] = '\0';
 
 
 
 
 
    //þifresiyi çözme
    for(i = 0; i < msgLen; ++i)
    decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
 	decryptedMsg[i] = '\0';
    
    
 
    printf("Original Message: %s", msg);
    printf("\nKey: %s", key);
    printf("\nNew Generated Key: %s", newKey);
    printf("\nEncrypted Message: %s", encryptedMsg);
    printf("\nDecrypted Message: %s", decryptedMsg);
 
	return 0;
}
