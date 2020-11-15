#ifndef __USER_H__
#define __USER_H__
#include <stdbool.h>//La <stdbool.h> nos sirve para poder usar los tipos de datos booleanos(falso o verdadero). Aunque claro, sabemos que es verdadero que se haya ido con otro :'v
#include <stdlib.h>//Libreria que contiene la funcion strcmp para cmparar vectores de char, bastante util xD.
#include <string.h>
#include <stdio.h>
char UserName[100], Passwd[20], Passwd2[20], UserName2[100];//Variables globales que vamos a usar en las funciones, son 3 vectores de char respectivamente y un int.
int option;
//Funcion que devuelve si el usuario ingresado es correcto, la funcion strcmp sirve para comparar cadenas de caracteres en C, se encuentra en la libreria <string.h>
bool CheckUser()
{
	if(strcmp(UserName, UserName2)==0)
		return true;
	else
		return false;
}
//Funcion que devuelve si la contraseña ingresada es correcta, lo mismo que la funcion CheckUser().
bool CheckPasswd()
{
	if(strcmp(Passwd, Passwd2)==0)
		return true;
	else
		return false;
}
//Funcion para limpiar la consola multiplataforma, comprueba primnero el sistema operativo para ejecutar el comando correcto.
void ConsoleClear()
{
	#ifdef _WIN32//Comprueba el Sistema Operativo, si se encuentra en windows ejecutara el comando "cls" para limpiar la consola, si se encuentra en mac o linux ejecutara "clear" 
		system("cls");
	#else
		system("clear");
	#endif

}
//Menu de login
void Login()
{
	printf("*************Menu de Ingreso***********\n");
	printf("+Usuario: "); scanf("%s", UserName2);
	printf("+Contraseña: "); scanf("%s", Passwd2);
	if(CheckUser()==true)//Llamo a la funcion y obtengo el resultado, si se ingreso correctamente se limpiara la consola mostrando el mensaje de bienbenida.
	{
		ConsoleClear();//Llamando a la funcion para limpiar la consola
		printf("*************************************\n");
		printf("*                                   *\n");
		printf("*          Bienvenido!              *\n");
		printf("*                                   *\n");
		printf("*************************************\n");
	}
}
void RegistryMenu()//El menu de registro, agregue la comprobacion de contraseña para asegurarse de que se tipeo correctamente.
{
	printf("*************Menu de Registro**********\n");
	printf("+Nombre de Usuario: "); scanf("%s", UserName);
	printf("+Contraseña: "); scanf("%s", Passwd);
	printf("+Vuelva a repetir su contraseña"); scanf("%s", Passwd2);
	if(CheckPasswd()==true)
	{
		ConsoleClear();
		printf("************Registro Correcto!**********\n");//Mensaje de registro correcto, preguntando al usuario si quiere ingresar o volver a registrarse.
		printf("0-Volver a Registrarse.\n");
		printf("1-Ingresar.\n");
		printf("Opcion[1/2]: "); scanf("%d", &option);
		if(option==1)
			Login();//Llamando a la funcion de logueo.
		else
			RegistryMenu();//Llamando a la funcion de menud de registro.
	}
	else
	{
		printf("***************Menu de Registro**************\n");
		printf("            Las contraseñás no coinciden!    \n");
		printf("Presione 0 para volver atras..."); getchar();
		ConsoleClear();
	}
	
}
#endif
