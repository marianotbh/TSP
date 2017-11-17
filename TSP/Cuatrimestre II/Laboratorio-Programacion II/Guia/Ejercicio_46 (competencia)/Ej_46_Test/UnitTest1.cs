using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Ejercicio_46;

namespace Ej_46_Test
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        public void TestValidarLista()
        {
            Competencia c = new Competencia(5, 3, Competencia.TipoCompetencia.F1);
            AutoF1 a = new AutoF1(3, "E");
            Assert.IsNotNull(c.Competidores);
            bool x = c + a;
            Assert.IsNotNull(c.Competidores);
        }

        [TestMethod]
        public void TestExcepcionCompetenciaNoDisponible()
        {
            Competencia c = new Competencia(5, 3, Competencia.TipoCompetencia.MotoCross);
            try
            {
                AutoF1 a = new AutoF1(5, "E");
                bool x = c + a;
            }
            catch(Exception e)
            {
                Assert.IsInstanceOfType(e, typeof(CompetenciaNoDisponibleException));
            }
        }

        [TestMethod]
        public void TestExcepcionCompetenciaDisponible()
        {
            Competencia c = new Competencia(5, 3, Competencia.TipoCompetencia.MotoCross);
            try
            {
                MotoCross m = new MotoCross(5, "E");
                bool x = c + m;
            }
            catch (CompetenciaNoDisponibleException e)
            {
                Assert.Fail();
            }
        }

        [TestMethod]
        public void TestAgregarALista()
        {
            Competencia c = new Competencia(5, 3, Competencia.TipoCompetencia.MotoCross);
            MotoCross m = new MotoCross(5, "E");
            bool x = c + m;
            x = c == m;
            Assert.AreEqual<bool>(true, x);
        }

        [TestMethod]
        public void TestSacarDeLista()
        {
            Competencia c = new Competencia(5, 3, Competencia.TipoCompetencia.MotoCross);
            MotoCross m = new MotoCross(5, "E");
            bool x = c + m;
            x = c == m;
            Assert.AreEqual<bool>(true, x);
            x = c - m;
            x = c != m;
            Assert.AreEqual<bool>(true, x);
        }
    }
}
