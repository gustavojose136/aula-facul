class Cidade {
    //propriedades
    private string nome;
    private int habitante;
    private double area;
    //métodos
   //método construtor (Nome do método é nome da Classe)
    public Cidade( string n, int h=0 ){
        this.nome = n;
        this.habitante = h;
    }

    public Cidade(){
        this.nome = "sem nome";
        this.habitante = 0;      
    }
    public string mostrarDados () {
        string mensagem;
        mensagem = "A cidade de " + this.nome + " possui " + Convert.ToString(this.habitante) + " de habitante.";
        return mensagem;
    }


public string mostrarDados(string oque){

    string mensagem;

    mensagem = "O nome da cidade é: " + this.nome + ".";

     if (oque == "T" || oque == "H") {
            mensagem += "\n Vivem nesta cidade " + Convert.ToString( this.habitante) + " habitantes.";
        }
        if (oque == "T" || oque == "A") {
            mensagem += "\n A cidade possui uma área de " + Convert.ToString(area) + " km2.";
        }
    return mensagem;
}

    public bool definirArea(double a){
        bool deuCerto = true;

        if (this.verificarDensidade(a) < 1){
            deuCerto = false;
        }else{
            this.area = a;
        }
        return deuCerto;
    }

    private double verificarDensidade(double a){
        double d;
        d = habitante/a;
        return d;
    }

}