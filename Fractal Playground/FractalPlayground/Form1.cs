﻿using System;
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
		FractalWork.Callback cb;

		public void Callback()
		{
			Invoke(new MethodInvoker(() => {
				unsafe
				{
					Text = "Done";
					Image.Save("yeah.png");
					refreshTimer.Stop();
					outputPanel.Invalidate();
				}
			}));
		}

		public Form1()
		{
			InitializeComponent();

			int width = 1920;
			int height = 1080;

			FractalWork.SetBufferSize((uint)width, (uint)height);
			cb = Callback;
			FractalWork.SetFinishedCallback(cb);

			unsafe
			{
				Image = new Bitmap(width, height, sizeof(uint) * width, System.Drawing.Imaging.PixelFormat.Format32bppArgb, new IntPtr(FractalWork.GetBuffer()));
			}
			outputPanel.BackgroundImage = Image;
			outputPanel.BackgroundImageLayout = ImageLayout.Zoom;
		}

		private void refreshTimer_Tick(object sender, EventArgs e)
		{
			outputPanel.Invalidate();
		}

		private void Form1_FormClosing(object sender, FormClosingEventArgs e)
		{
			FractalWork.Abort();
		}

		private void Form1_Load(object sender, EventArgs e)
		{ 
			
			FractalWork.Start();
			refreshTimer.Start();
		}
	}
}
