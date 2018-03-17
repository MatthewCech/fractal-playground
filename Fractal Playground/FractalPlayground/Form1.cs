using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FractalPlayground
{
	public partial class Form1 : Form
	{
		public void Callback(ulong size, int[] characters)
		{
			Text = "what is this???????";
		}

		public Form1()
		{
			InitializeComponent();

			FractalWork.SetFinishedCallback(Callback);
		}
	}
}
