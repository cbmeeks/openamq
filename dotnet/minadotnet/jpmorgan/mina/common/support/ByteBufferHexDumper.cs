using System.Text;
using jpmorgan.mina.common;

namespace jpmorgan.mina.common.support
{
    public class ByteBufferHexDumper
    {
        private static byte[] highDigits;
        
        private static byte[] lowDigits;
        
        static ByteBufferHexDumper()
        {
            byte[] digits = { (byte)'0', (byte)'1', (byte)'2', (byte)'3', (byte)'4', (byte)'5', (byte)'6',
                              (byte)'7', (byte)'8', (byte)'9', (byte)'A', (byte)'B', (byte)'C', (byte)'D', 
                              (byte)'E', (byte)'F' };
            int i;
            byte[] high = new byte[256];
            byte[] low = new byte[256];
            
            for (i = 0; i < 256; i++)
            {
                high[i] = digits[i >> 4];
                low[i] = digits[i & 0x0F];                
            }
            
            highDigits = high;
            lowDigits = low;
        }
        
        public static string GetHexDump(ByteBuffer input)
        {
            int size = input.Position;
            if (size == 0)
            {
                return "empty";
            }
            
            StringBuilder output = new StringBuilder(size * 3 - 1);

            byte[] data = input.ToByteArray();
            int byteValue = data[0] & 0xFF;
            output.Append((char) highDigits[byteValue]);
            output.Append((char) lowDigits[byteValue]);            
            
            for (int i = 1 ; i < size; i++)
            {
                output.Append(' ');
                byteValue = data[i] & 0xFF;
                output.Append((char) highDigits[byteValue]);
                output.Append((char) lowDigits[byteValue]);
            }
            
            return output.ToString();
        }
    }
}
