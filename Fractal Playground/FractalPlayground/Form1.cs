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
		Bitmap Image;

		public void Callback()
		{
			Invoke(new MethodInvoker(() => {
				unsafe
				{
					//Image = new Bitmap(1920, 1080, sizeof(uint) * 1920, System.Drawing.Imaging.PixelFormat.Format32bppArgb, new IntPtr(FractalWork.GetBuffer()));
					Text = "Done";
					Image.Save("yeah.png");
				}
			}));
		}

		public Form1()
		{
			InitializeComponent();

			FractalWork.SetBufferSize(1920, 1080);
			FractalWork.SetFinishedCallback(Callback);

			unsafe
			{
				Image = new Bitmap(1920, 1080, sizeof(uint) * 1920, System.Drawing.Imaging.PixelFormat.Format32bppArgb, new IntPtr(FractalWork.GetBuffer()));
			}
			outputPanel.BackgroundImage = Image;
			outputPanel.BackgroundImageLayout = ImageLayout.Zoom;

			Invalidate();

			FractalWork.Start();
			refreshTimer.Start();
		}

		private void refreshTimer_Tick(object sender, EventArgs e)
		{
			outputPanel.Invalidate();
		}

		private void Form1_FormClosing(object sender, FormClosingEventArgs e)
		{
			FractalWork.Abort();
		}
	}
}
