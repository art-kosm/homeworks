#pragma once

struct PhoneListElement;
struct PhoneList;

PhoneList *createPhoneList();
void importList(PhoneList *list, char *path);
void exportList(PhoneList *list);
void add(PhoneList *list, char *name, char *phone);
void findPhone(PhoneList *list, char *name);
void findName(PhoneList *list, char *phone);
void deleteList(PhoneList *list);
