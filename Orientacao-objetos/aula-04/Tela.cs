class Tela{
    // propriedades
    private int corFundo;
    private int corFonte;

    // métodos
    public Tela(){
        this.corFundo = 0;
        this.corFonte = 15;
    }

    public int mostrarMenu(int col, int lin, List<string>opcoes){
        int escolha = 0;

        Console.SetCursorPosition(col,lin);
        Console.Write("---=== Menu ===---");
        lin++;

        for (int x=0; x<opcoes.Count; x++){
            Console.SetCursorPosition(col,lin);
            Console.Write( opcoes[x] );
            lin++;
        }
        Console.SetCursorPosition(col,lin);
        Console.Write("opçao : ");
        escolha = Convert.ToInt16(Console.ReadLine());

        return escolha;
    }


    public void prepararTela(string msg=""){
        int lin = 1;
        int col = 1;
        
        Console.Clear();
        for(lin=0; lin<=24; lin++){
            Console.SetCursorPosition(0,lin);
            Console.Write("|");
            Console.SetCursorPosition(79,lin);
            Console.Write("|");
        }

        for(col=0; col<=79; col++){
            Console.SetCursorPosition(col,0);
            Console.Write("-");
            Console.SetCursorPosition(col,24);
            Console.Write("-");
        }

        Console.SetCursorPosition(0,0); Console.Write("+");
        Console.SetCursorPosition(0,24); Console.Write("+");
        Console.SetCursorPosition(79,0); Console.Write("+");
        Console.SetCursorPosition(79,24); Console.Write("+");

        col = (80-msg.Length)/2;
        Console.SetCursorPosition(col,1);
        Console.Write(msg);
    }


}