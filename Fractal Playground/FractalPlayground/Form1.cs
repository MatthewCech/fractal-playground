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
		public static void Callback(ulong size, int[] characters)
		{
			Console.WriteLine("Yeah!");
		}

		public Form1()
		{
			InitializeComponent();

			FractalWork.SetFinishedCallback(Callback);

		}
	}
}
