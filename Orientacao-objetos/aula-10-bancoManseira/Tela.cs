class Tela {
    //propriedades
    ConsoleColor corTexto, corFundo;
    public Tela(ConsoleColor ct=ConsoleColor.White, ConsoleColor cf=ConsoleColor.Black){
        this.corFundo = cf;
        this.corTexto = ct;
        this.ConfigurarTela();
    }
    public void ConfigurarTela(){
        Console.BackgroundColor = this.corFundo;
        Console.ForegroundColor = this.corTexto;
        Console.Clear();
    }
    public void montarTelaSistema(){
        this.montarMoldura(0,0,79,24);
        this.montarLinhaHor(2,0,79);
        this.centralizar(2,0,79, "Banco Lukas");
    }
    public void montarMoldura(int ci, int li, int cf, int lf){
        int col, lin;
        this.limparArea(ci,li,cf,lf);
        //desenha as linhas horizontais
        for(col=ci; col<=cf; col++){
            Console.SetCursorPosition(col,li);
            Console.Write("-");
            Console.SetCursorPosition(col,lf);
            Console.Write("-");
        }
        //desenha as linhas verticais
        for(lin=li; lin<=lf; lin++){
            Console.SetCursorPosition(ci,lin);
            Console.Write("|");
            Console.SetCursorPosition(cf,lin);
            Console.Write("|");
        }
        //desenha os cantos da moldura
        Console.SetCursorPosition(ci,li); Console.Write("+");
        Console.SetCursorPosition(ci,lf); Console.Write("+");
        Console.SetCursorPosition(cf,li); Console.Write("+");
        Console.SetCursorPosition(cf,lf); Console.Write("+");
    }
    public void limparArea(int ci, int li, int cf, int lf){
        int col, lin;
        //para cada coluna
        for(col=ci; col<=cf; col++){
            //em cada uma das linhas
            for(lin=li;lin<=lf;lin++){
                //posiciona
                Console.SetCursorPosition(col,lin);
                //imprime 1 espaço em branco para "limpar"
                Console.Write(" ");
            }
        }
    }
    public void montarLinhaHor(int lin, int ci, int cf){
        int col;
        //traça a linha
        for(col=ci; col<=cf; col++){
            Console.SetCursorPosition(col, lin);
            Console.Write("-");
        }
        //arruma as pontas
        Console.SetCursorPosition(ci,lin);
        Console.Write("+");
        Console.SetCursorPosition(cf,lin);
        Console.Write("+");
    }
    public void centralizar(int lin, int ci, int cf, string msg){
        int col;
        col = ci + ((cf-ci)/2);
        Console.SetCursorPosition(col,lin);
        Console.Write(msg);
    }
}