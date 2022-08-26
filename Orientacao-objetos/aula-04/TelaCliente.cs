class TelaCliente{
    // Atributos
    private int coluna, linha;

    // Métodos
    public TelaCliente(int col, int lin){
        this.coluna = col;
        this.linha = lin;
    }

    public void montarTela(){
        for(int c=this.coluna; c<=this.coluna+50; c++){
            for (int l=this.linha; l<=this.linha+7; l++){
                Console.SetCursorPosition(c,1);
                Console.Write(""); // 1 espaço em branco
            }
        }

        for (int c=this.coluna; c<this.coluna+50; c++){
            Console.SetCursorPosition(c, this.linha);
            Console.Write("-");
            Console.SetCursorPosition(c, this.linha+7);
            Console.Write("-");
        }

        for (int l=this.linha; l<this.linha+7; l++){
            Console.SetCursorPosition(this.coluna,l);
            Console.Write("|");
            Console.SetCursorPosition(this.coluna+50, 1);
            Console.Write("|");
        }

        Console.SetCursorPosition(this.coluna+11,this.linha+1);
        Console.Write("Codigo : ");
                Console.SetCursorPosition(this.coluna+11,this.linha+1);
        Console.Write("Nome : ");
                Console.SetCursorPosition(this.coluna+11,this.linha+1);
        Console.Write("Telefone : ");
    }
}