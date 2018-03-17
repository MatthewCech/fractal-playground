using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace FractalPlayground
{
	unsafe struct Wow
	{
		public int wow;
		public byte* str;
	}

	static class Program
	{
		
		[DllImport("Fractal Work.dll")]
		unsafe static extern void* Oh();

		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		static void Main()
		{
			Application.EnableVisualStyles();
			Application.SetCompatibleTextRenderingDefault(false);
			Form f = new Form1();
			Wow wow;
			string nam;
			unsafe
			{
				void* ptr = Oh();
				wow = Marshal.PtrToStructure<Wow>(new IntPtr(ptr));
				nam = Marshal.PtrToStringAnsi(new IntPtr(wow.str));
			}
			
			f.Text = nam;
			Application.Run(f);

			
		}
	}
}
