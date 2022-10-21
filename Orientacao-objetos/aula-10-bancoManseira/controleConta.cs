class ControleConta{
    // atributos
    Tela tela;
    List<Conta> bancoDados = new List<Conta>();
    int posicao;
    string numConta;
    string titConta;
    // métodos
    public ControleConta(Tela t){
        this.tela = t;
        // cria uma primeira conta só pra ter alguma coisa no banco
        bancoDados.Add(new Conta("Gustavo",10000));
    }
    public void executarCRUD(){
        while(true){
            // montar a tela do CRUD de contas
            this.tela.montarMoldura(10,5,70,14);
            this.tela.montarLinhaHor(8,10,70);
            this.tela.centralizar(6,10,70,"CRUD de Contas");
            this.montarTelaConta();
            //solicita o numero da conta
            Console.SetCursorPosition(21,9);
            this.numConta = Console.ReadLine();
            if(this.numConta == "") break;
            // procura no banco de dados se existe o numero da conta informada
            bool achou = false;
            for(int x=0; x<this.bancoDados.Count; x++){
                if(this.bancoDados[x].numero == this.numConta){
                    achou = true;
                    this.posicao = x;
                    break;
                }
            }
            /* mostra os dados da conta, caso tenha encontrado ou 
            mostra a mensagem de conta não encontrada */
            if(achou){
                // achou a conta e vai mostrar os dados
                this.mostrarDadosConta();
                Console.ReadKey();
            } else{
                /* não achou a conta, mostra a mensagem e 
                pergunta se deseja cadastrar uma nova conta */
            }
        }
    }
    public void montarTelaConta(){
        Console.SetCursorPosition(11,9);
        Console.Write("Numero  :");
        Console.SetCursorPosition(11,10);
        Console.Write("Titular :");
        Console.SetCursorPosition(11,11);
        Console.Write("Saldo   :");
    }
    public void mostrarDadosConta(){
        Console.SetCursorPosition(21,10);
        Console.Write(this.bancoDados[this.posicao].titular);
        Console.SetCursorPosition(21,11);
        Console.Write(this.bancoDados[this.posicao].saldo);
    }
}