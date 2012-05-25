
void transferir(){
  
  long tam=0;  
  
  char *buf;      //buffer de tamanho de envio
  
  printf("identifique o arquivo: ");
  char localfile[1024];    // dizer o local e nome do arquivo a ser copiado ou donwloado
  gets(localfile);
  
  
  FILE *arq=fopen(localfile,"rb");
  if(!arq){
    printf("erro arquivo inexistente\n");
  }
  
  fseek(arq,0,SEEK_END);
  long tamanho=ftell(arq);              // ver o tamanho do arquivo
  rewind(arq);
  
  
  
  
  
  printf("destino o arquivo: ");
  char destinofile[1024];            //informar o local de destino do arquvio;
  gets(destinofile);
  
  
  FILE *arq1=fopen(destinofile,"ab");
  if(!arq1){
    printf("arquivo nao criado");
    
  }
          
      
    if(tamanho > 1024){	                		// se arquivo maior que 1mb 
        buf = (char*)malloc(sizeof(char)*1025);		// alocando memoria
	    while(tam < tamanho){	
		int ler = fread_s(buf, 1025, sizeof(char),arq);      //lendo do arquivo
		int envia = send(sockfd, buf, ler, 0);			//copiando pra o socket
		tam +=envia;		//alterando a variavel pra continuar o while
		fflush(arq);	
            
      }else{                           // se arquivo menor que 1mb
	buf=(char*)malloc(sizeof(tamanho)+1);      //aloca memoria com tamnaho total do arquivo
	int reading=fread(buf,1,tamanho,arq);      // lendo do arquivo
	int writing=send(sockfd, buf, Reading, 0);  // copiando pra o socket
        fflush(arq);
      
    }
      
    fclose(arq);
    fclose(arq1);
    free(buf);
}























