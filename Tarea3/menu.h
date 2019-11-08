#ifndef MENU_H
#define MENU_H
#include "library.h"
#include "managerest.h"
#include "filesmanager.h"
class menu
{
public:
    managerEST EST;
    menu();
    void shareMenu();
    string BANNER ="XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";

    string MENU = "::::    ::::: :::::::::: ::::    ::: :::    :::      \n"
                  "+:+:+: :+:+:+ :+:        :+:+:   :+: :+:    :+:      \n"
                  "+:+ +:+:+ +:+ +:+        :+:+:+  +:+ +:+    +:+      \n"
                  "+#+  +:+  +#+ +#++:++#   +#+ +:+ +#+ +#+    +:+      \n"
                  "+#+       +#+ +#+        +#+  +#+#+# +#+    +#+      \n"
                  "#+#       #+# #+#        #+#   #+#+# #+#    #+#      \n"
                  "###       ### ########## ###    ####  ########";

};

#endif // MENU_H
