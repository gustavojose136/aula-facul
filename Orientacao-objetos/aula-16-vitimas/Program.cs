Tela tela = new Tela(ConsoleColor.Green, ConsoleColor.Yellow);
CRUD crud = new CRUD(tela);

while (true){
    tela.preparaTela();
    tela.escrever(1, 1, "Menu");
    tela.escrever(1, 2, "1 - Alvos");
    tela.escrever(1, 3, "0 - Sair");
    string op = tela.perguntar(1, 4, "Opção: ");

    if (op == "1"){
        crud.executarCRUD();
    } else {
        break;
    }
}