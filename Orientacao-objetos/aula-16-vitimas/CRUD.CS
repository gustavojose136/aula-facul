class CRUD{
    // atributos
    Alvos alvo = new Alvos();
    List<Alvos> vitimas = new List<Alvos>();
    int posicao;
    Tela tela;
    // construtor
    public CRUD(Tela t){
        this.tela = t;

        vitimas.Add(new Alvos(1, "João", "R$ 1000,00", true));
    }
    // outros métodos
    public void executarCRUD(){
        while(true){
            // mostra tela
            this.tela.escrever(10,5,"Cadastro de Alvos");
            // pergunta codigo
            this.alvo.codigo = Convert.ToInt16(
                this.tela.perguntar(10,6,"Código: "));
            
            // procura codigo
            bool achou = false;
            for(int x=0; x<this.vitimas.Count; x++){
                if(this.alvo.codigo == this.vitimas[x].codigo){
                    this.alvo = this.vitimas[x];
                    achou = true;
                    this.posicao = x;
                    break;
                }
            }
            // se achou codigo
            if(achou){
            //      mostra os dados do registo
                this.tela.escrever(10,7,"Nome: " + this.alvo.nome);
                this.tela.escrever(10,8,"Valor: " + Convert.ToString(this.alvo.valor));
                this.tela.escrever(10,9,"Entidade Viva: " + Convert.ToString(this.alvo.entVivo));
            //      pergunta se deseja A/E
                string resp = this.tela.perguntar(10,11,"Alterar/Excluir/Voltar (A/E/V): ");
                //      se deseja ALTERAR
                if (resp.ToUpper() == "A"){
            //          pergunta novos dados
            //          pede para confirmar novos dados
            //          se confirmado
            //              grava os novos dados
                }
                //      se deseja EXCLUIR
                else if (resp.ToUpper() == "E"){
            //          pede para confirmar exclusão
            //          se confirmado
            //              exclui o registro
                }
            }
            else if(!achou){
            // se não achou codigo
            //      informa que não encontrou
            //      pergunta se deseja cadastrar
            //      se confirmado
            //          pergunta dados do registro
            //          pergunta se confirma registro
            //          se confirmado
            //              cadastra novo registro
            }
        }
    }
}