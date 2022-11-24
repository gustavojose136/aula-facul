# Protocolo de Aplicação
# programa SERVIDOR

from socket import *

# definir a porta que será monitorada
porta = 12000

# cria o socket para o programa do servidor
socketServidor = socket(AF_INET,SOCK_STREAM)
# liga o socket na porta
socketServidor.bind( ('',porta) )
# começa a monitorar (escutar) a porta 
socketServidor.listen(True)

print("Servidor escutando a porta ",porta)

while True:
    cliente, endereco = socketServidor.accept()
    
    mensagemRecebida = cliente.recv(1024)
    mensagemRecebida = mensagemRecebida.decode()
    
    print ("Rebido ", mensagemRecebida, ". De ", endereco)
    
    # aqui é onde, de fato, o protocolo é resolvido
    if (mensagemRecebida == "oi"):
        retorno = "fala cara"
    elif (mensagemRecebida == "tudo bem?"):
        retorno = "tá tudo beeem mais ou menos"
    elif (mensagemRecebida == "quais as novidades?"):
        retorno = "O Lofy caiu do berço"
    elif (mensagemRecebida == "ele tá bem?"):
        retorno = "tá vivo... bem é outra coisa"
    else:
        retorno = "não entendi"
        
    retorno = retorno.encode()
    cliente.send(retorno)
    
    cliente.close()