class Alvos
{
    //atributos
    public int codigo;
    public string nome;
    public string valor;
    public bool entVivo;


    //construtores
    public Alvos(){
        this.codigo = 0;
        this.nome = "";
        this.valor = "";
        this.entVivo = false;
    }

    public Alvos(int cod, string nom, string val, bool ent){
        this.codigo = cod;
        this.nome = nom;
        this.valor = val;
        this.entVivo = ent;
    }

    //outros métodos
}