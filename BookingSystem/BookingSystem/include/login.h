#pragma once
#include "pch.h"
#include "../../Dependencies/bcrypt.h"
#include "../../BLL/include/credentials.h"
#include "../../BLL/include/register.h"
#include "../../DAL/include/files.h"

class Login {
public:
	void display(PageHandler& pages);
	void inputCreds();
	void checkCreds();
	

};