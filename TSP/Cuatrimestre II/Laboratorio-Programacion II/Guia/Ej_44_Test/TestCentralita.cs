using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Ejercicio_44;

namespace Ej_44_Test
{
    [TestClass]
    public class TestCentralita
    {
        [TestMethod]
        public void TestListaDeLlamadas()
        {
            Centralita c = new Centralita("Mariano Center");
            Assert.IsNotNull(c.Llamadas);        
        }

        [TestMethod]
        public void TestCentralitaExceptionLocal()
        {
            Centralita c = new Centralita("Mariano Center");
            Local local = new Local("Origen", 15f, "Destino", 15.55f);
            Local repe = new Local(local, 15.66f);

            c += local;
            try
            {
                c += repe;
            }
            catch(Exception e)
            {
                Assert.IsInstanceOfType(e, typeof(CentralitaException));
            }
        }

        [TestMethod]
        public void TestCentralitaExceptionProvincial()
        {
            Centralita c = new Centralita("Mariano Center");
            Provincial provincial = new Provincial(15.55f, Provincial.Franja.Franja_1, "Origen", "Destino");
            Provincial repe = new Provincial(Provincial.Franja.Franja_2, provincial);

            c += provincial;
            try
            {
                c += repe;
            }
            catch (Exception e)
            {
                Assert.IsInstanceOfType(e, typeof(CentralitaException));
            }
        }

        [TestMethod]
        public void TestOperadorIgualIgual()
        {
            Local l1 = new Local("Origen", 15.0f, "Destino", 15.45f);
            Local l2 = new Local("Origen", 10f, "Destino", 12.50f);
            Provincial p1 = new Provincial(55f, Provincial.Franja.Franja_1, "Origen", "Destino");
            Provincial p2 = new Provincial(34f, Provincial.Franja.Franja_2, "Origen", "Destino");
            bool x;

            x = l1 == l2;
            Assert.AreEqual<bool>(true, x);

            x = p1 == p2;
            Assert.AreEqual<bool>(true, x);

            x = l1 == p1;
            Assert.AreEqual<bool>(false, x);

            x = l2 == p2;
            Assert.AreEqual<bool>(false, x);

            x = l2 == p1;
            Assert.AreEqual<bool>(false, x);

            x = l1 == p2;
            Assert.AreEqual<bool>(false, x);
        }
    }
}
