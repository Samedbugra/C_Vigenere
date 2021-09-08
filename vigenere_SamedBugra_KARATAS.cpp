#include<stdio.h>
#include<string.h>

int main(){
    char msg[] = "SAMEDBUGRAKARATAS"; 								/* �ifrelenecek metni dizide tutuyoruz  */
    char key[] = "MERHABA";											/* Anahtar kelimeyi dizide tutuyoruz  */
    int msgLen = strlen(msg), keyLen = strlen(key), i, j;			/* metnin ve anahtar�n uzunlu�unu de�i�kenlere at�yoruz  */
 
    char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen]; /* metnin uzunlu�unu(boyutunu) 3 farkl� dizide tutuyoruz  */
 
    //generating new key
    for(i=0, j=0; i<msgLen; ++i, ++j)							/*   */
	{
        if(j == keyLen)
            j = 0;
 
        newKey[i] = key[j];
    }
 	newKey[i] = '\0';
 
 
 
 
    //�ifreleme
    for(i=0; i<msgLen; ++i)
        encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';
    encryptedMsg[i] = '\0';
 
 
 
 
 
    //�ifresiyi ��zme
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
