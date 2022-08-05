class pessoa{
	public:
		string nome;
		int idade;
		
		void apresentar_se(){
			cout << "Meu nome eh " << this->nome
				 << ", e tenho " << this->idade
				 << " anos de idade" << endl;
		}
};
