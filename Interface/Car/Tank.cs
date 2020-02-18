using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Car
{
    class Tank
    {
        uint volume;
        double fuel;
        public uint Volume
        {
            get => volume;
            private set => volume = value >= 40 && value <= 120 ? value : throw new Exception("Bad tank volume");
        }
        public double Fuel
        {
            get => fuel;
            set
            {
                if (value <= 0 )
                {
                    fuel = 0;
                }
            }
        }
    }
}
