using System.Runtime.InteropServices;


namespace FractalPlayground
{
	unsafe public class FractalWork
	{
		public delegate void Callback(ulong size, int[] characters);

		[DllImport("Fractal Work.dll")]
		public static extern void SetFinishedCallback(Callback callback);
	}
}
