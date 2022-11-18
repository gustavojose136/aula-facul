using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Whatsap2
{
    /// <summary>
    /// Interação lógica para MainWindow.xam
    /// </summary>
    public partial class MainWindow : Window
    {
        List<Cliente> clientes = new List<Cliente>();

        public MainWindow()
        {
            InitializeComponent();

            //Adiciona alguns clientes
            //para o grid não ficar vazio

            clientes.Add(new Cliente() { Codigo = 1, Nome = "Gustavo", Email = "gjose2980@gmail.com", vivo = false });
            clientes.Add(new Cliente() { Codigo = 2, Nome = "Nizio", Email = "gujose834@gmail.com", vivo = false });
            clientes.Add(new Cliente() { Codigo = 3, Nome = "Benzema", Email = "benzema2980@gmail.com", vivo = true });

            //atualizar datagrid

            DTGclientes.ItemsSource = clientes;
            DTGclientes.Items.Refresh();
        }

        public void navegar()
        {
            BTNcadastrar.IsEnabled = true;
            BTNmodificar.IsEnabled = true;
            BTNgravar.IsEnabled = false;
            BTNcancelar.IsEnabled = false;
            TBXid.IsEnabled = false;
            TBXnome.IsEnabled = false;
            TBXemail.IsEnabled = false;
        }

        public void editar()
        {
            BTNcadastrar.IsEnabled = false;
            BTNmodificar.IsEnabled = false;
            BTNgravar.IsEnabled = true;
            BTNcancelar.IsEnabled = true;
            TBXid.IsEnabled = true;
            TBXnome.IsEnabled = true;
            TBXemail.IsEnabled = true;
        }


        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            this.navegar();
        }
    }
}
