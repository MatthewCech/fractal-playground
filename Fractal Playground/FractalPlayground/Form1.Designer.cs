namespace FractalPlayground
{
	partial class Form1
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			this.outputPanel = new System.Windows.Forms.Panel();
			this.refreshTimer = new System.Windows.Forms.Timer(this.components);
			this.SuspendLayout();
			// 
			// outputPanel
			// 
			this.outputPanel.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
			this.outputPanel.BackColor = System.Drawing.Color.Black;
			this.outputPanel.Location = new System.Drawing.Point(12, 12);
			this.outputPanel.Name = "outputPanel";
			this.outputPanel.Size = new System.Drawing.Size(776, 426);
			this.outputPanel.TabIndex = 0;
			// 
			// refreshTimer
			// 
			this.refreshTimer.Tick += new System.EventHandler(this.refreshTimer_Tick);
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(800, 450);
			this.Controls.Add(this.outputPanel);
			this.Name = "Form1";
			this.Text = "Form1";
			this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.Panel outputPanel;
		private System.Windows.Forms.Timer refreshTimer;
	}
}

