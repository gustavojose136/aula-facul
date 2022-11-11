class Tela{
    //atributos
    ConsoleColor cf, ct;

    //metodos
    public Tela(ConsoleColor f, ConsoleColor t){
        this.cf = f;
        this.ct = t;

        this.preparaTela();
    }

    public void preparaTela(){
        Console.BackgroundColor = this.cf;
        Console.ForegroundColor = this.ct;
        Console.Clear();
    }

    public string perguntar(int col, int lin, string perg){
        string resp="";
        this.escrever(col, lin, perg);
        resp = Console.ReadLine();
        return resp;
    }

    public void escrever(int col, int lin, string msg){
        Console.SetCursorPosition(col, lin);
        Console.Write(msg);
    }
}