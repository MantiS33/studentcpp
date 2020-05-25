using System;
using System.Linq;
using System.Windows.Forms;

namespace ApiTest
{
    public partial class AuthF : Form
    {
        private string _authorizeUri = "https://oauth.vk.com/authorize";
        private string _redirectUri = "https://oauth.vk.com/blank.html";

        private int _clientId = 7481626;

        public string _token { get; private set; }

        public AuthF()
        {
            InitializeComponent();
        }

        private void AuthFormShown(object sender, EventArgs e)
        {
            webBrowser.Navigate(
                new Uri("https://oauth.vk.com/authorize?"
                        + $"client_id={_clientId}&display=page&redirect_uri={_redirectUri}&"
                        + "response_type=token&v=5.92&state=123456"));
        }

        private void WebBrowserNavigated(object sender, WebBrowserNavigatedEventArgs e)
        {
            string uri = e.Url.ToString();
            if (uri.StartsWith(_authorizeUri)) return;

            if (!uri.StartsWith(_redirectUri))
            {
                DialogResult = DialogResult.No;
                return;
            }

            var parameters = (from param in uri.Split('#')[1].Split('&')
                              let parts = param.Split('=')
                              select new
                                  {
                                      Name = parts[0],
                                      Value = parts[1]
                                  }
                             ).ToDictionary(v => v.Name, v => v.Value);

            _token = parameters["access_token"];
            DialogResult = DialogResult.Yes;
        }
    }
}