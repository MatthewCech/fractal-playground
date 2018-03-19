using System;
using System.Runtime.InteropServices;


namespace FractalPlayground
{
	unsafe public class FractalWork
	{
		public delegate void Callback();
		
		[DllImport("Fractal Work.dll")]
		public static extern void SetBufferSize(uint width, uint height);

		[DllImport("Fractal Work.dll")]
		public static extern uint* GetBuffer();

		[DllImport("Fractal Work.dll")]
		public static extern void SetFinishedCallback(Callback callback);

		[DllImport("Fractal Work.dll")]
		public static extern void Start();

		[DllImport("Fractal Work.dll")]
		public static extern void Abort();

	}
}
