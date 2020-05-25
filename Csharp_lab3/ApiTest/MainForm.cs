using System;
using System.Net;
using System.Text;
using System.Windows.Forms;
using Newtonsoft.Json.Linq;

namespace ApiTest
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private string Token { get; set; }
        private string Conditions { get; set; }

        private void AuthClick(object sender, EventArgs e)
        {
            Token = null;
            using (AuthF authForm = new AuthF())
            {
                if (authForm.ShowDialog() == DialogResult.Yes) Token = authForm._token;
            }

            if (string.IsNullOrEmpty(Token))
            {
                MessageBox.Show("Ошибка авторизации", "Ошибка",
                                MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
        }
        

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton rb = (RadioButton)sender;
            if (rb.Checked)
            {
                string template = "https://api.vk.com/method/{0}?{1}&access_token={2}&v=5.92";

                var client = new WebClient { Encoding = Encoding.UTF8 };
                string json = client.DownloadString(string.Format(template, "friends.get", "order=name&count=3&fields=city.domain&name_case=nom", Token));

                JObject jsonObject = JObject.Parse(json);
                Log.Text = jsonObject.ToString();
            }
            
        }

        private void radioButton3_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton rb = (RadioButton)sender;
            if (rb.Checked)
            {
                string template = "https://api.vk.com/method/{0}?{1}&access_token={2}&v=5.92";

                var client = new WebClient { Encoding = Encoding.UTF8 };
                string json = client.DownloadString(string.Format(template, "database.getCountries", "need_all=1", Token));

                JObject jsonObject = JObject.Parse(json);
                Log.Text = jsonObject.ToString();
            }
            
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton rb = (RadioButton)sender;
            if (rb.Checked)
            {
                string template = "https://api.vk.com/method/{0}?{1}&access_token={2}&v=5.92";

                var client = new WebClient { Encoding = Encoding.UTF8 };
                string json = client.DownloadString(string.Format(template, "groups.get", "extended=1&count=3", Token));

                JObject jsonObject = JObject.Parse(json);
                Log.Text = jsonObject.ToString();
            }
        }

        private void radioButton4_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton rb = (RadioButton)sender;
            if (rb.Checked)
            {
                string template = "https://api.vk.com/method/{0}?{1}&access_token={2}&v=5.92";

                var client = new WebClient { Encoding = Encoding.UTF8 };
                string json = client.DownloadString(string.Format(template, "friends.get", "order=name&count=3&fields=city.domain&name_case=nom", Token));

                JObject jsonObject = JObject.Parse(json);
                Log.Text = jsonObject.ToString();
            }
        }
    }
}