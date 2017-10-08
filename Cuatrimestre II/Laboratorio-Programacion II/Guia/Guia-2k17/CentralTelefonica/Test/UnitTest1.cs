using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

using CentralTelefonica;

namespace Test
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void CentralitaIsNotNull()
        {
            Centralita central = new Centralita("Central");
            
            Assert.IsNotNull(central.Llamadas);
        }

        [TestMethod]
        public void ControlCentralitaException()
        {
            Centralita central = new Centralita("Central");
            Provincial prov1 = new Provincial("444 444", Provincial.Franja.Franja_1, 20f, "222 222");
            Provincial prov2 = new Provincial(Provincial.Franja.Franja_3, prov1);
            central += prov1;
            try
            {
                central += prov2;
            }
            catch (Exception e)
            {
                Assert.IsInstanceOfType(e, typeof(CentralitaException));
            }
        }
    }
}
