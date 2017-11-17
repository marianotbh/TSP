class Persona:
    def __init__(self):
        self.nombre = ""
        self.edad = 0
    
    def setEdad(self,edad):
        self.edad = edad
    
    def setNombre(self,nombre):
        self.nombre = nombre
    
    def printPersona(self):
        print("Nombre: " + self.nombre + " - Edad: " + str(self.edad) + "\n")
    
    def esMayorQue(self,p2):
        if(self.edad > p2.edad):
            return True
        else:
            return False
#fin de clase Persona

#inicio del programa
p1 = Persona()
p2 = Persona()
p1.setNombre("Juancito")
p1.setEdad(99)
p2.setNombre("Jaime")
p2.setEdad(150)

print(p1.esMayorQue(p2))

lista = [p1,p2,p1,p2]

for item in lista:
    item.printPersona()

#for i in range(0,len(lista)):
#    print(i)
#    pAux = lista[i]
#    pAux.printPersona()

