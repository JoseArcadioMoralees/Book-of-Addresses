#include "RecipientManager.h"

void RecipientManager::addRecipient()
{
    Recipient adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = setDataOfTheNewRecipient();

    recipients.push_back(adresat);
    recipientFile.addRecipientToFile(adresat);

}

Recipient RecipientManager::setDataOfTheNewRecipient()
{
    Recipient adresat;

    adresat.setId(recipientFile.getIdOfLastRecipient() + 1);
    adresat.setIdOfUser(ID_OF_LOGGED_USER);

    cout << "Podaj imie: ";
    adresat.setName(AuxiliaryMethods::loadALine());
    adresat.setName(replaceFirstLetterToUppercaseAOthersToLowercase(adresat.getName()));

    cout << "Podaj nazwisko: ";
    adresat.setSurname(AuxiliaryMethods::loadALine());
    adresat.setSurname(replaceFirstLetterToUppercaseAOthersToLowercase(adresat.getSurname()));

    cout << "Podaj numer telefonu: ";
    adresat.setPhoneNumber(AuxiliaryMethods::loadALine());

    cout << "Podaj email: ";
    adresat.setEmail(AuxiliaryMethods::loadALine());

    cout << "Podaj adres: ";
    adresat.setAddress(AuxiliaryMethods::loadALine());

    return adresat;
}


string RecipientManager::replaceFirstLetterToUppercaseAOthersToLowercase(string tekst)
{
    if (!tekst.empty())
    {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}


void RecipientManager::shawAllRecipients()
{
    recipients = loadLoggedUserRecipientsFromFile(); 
    system("cls");
    if (!recipients.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Recipient> :: iterator itr = recipients.begin(); itr != recipients.end(); itr++)
        {
            shawRecipientData(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void RecipientManager::shawRecipientData(Recipient adresat)
{
    cout << endl << "Id:                 " << adresat.getId() << endl;
    cout << "Imie:               " << adresat.getName() << endl;
    cout << "Nazwisko:           " << adresat.getSurname() << endl;
    cout << "Numer telefonu:     " << adresat.getPhoneNumber() << endl;
    cout << "Email:              " << adresat.getEmail() << endl;
    cout << "Adres:              " << adresat.getAddress() << endl;
}


vector <Recipient> RecipientManager::loadLoggedUserRecipientsFromFile()
{
    recipients = recipientFile.loadLoggedUserRecipientsFromFile(ID_OF_LOGGED_USER); 
    return recipients;  
}

void RecipientManager::deleteRecipient()
{
    int idUsuwanegoAdresata = 0;
    int numerLiniiUsuwanegoAdresata = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = getTheIdOfTheRecipient();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Recipient>::iterator itr = recipients.begin(); itr != recipients.end(); itr++)
    {
        if (itr -> getId() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = AuxiliaryMethods::loadCharacter();
            if (znak == 't')
            {
                numerLiniiUsuwanegoAdresata = recipientFile.returnRecipientLineNumber(idUsuwanegoAdresata);
                recipientFile.deleteChosenLineInFile(numerLiniiUsuwanegoAdresata);
                recipients.erase(itr);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                return;
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
                return;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
    return;
}

int RecipientManager::getTheIdOfTheRecipient()
{
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = AuxiliaryMethods::loadIntegerNumber();
    return idWybranegoAdresata;
}

void RecipientManager::editRecipient()
{
    system("cls");
    Recipient adresat;
    int idEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = getTheIdOfTheRecipient();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (unsigned int i = 0; i < recipients.size(); i++)
    {
        if (recipients[i].getId() == idEdytowanegoAdresata)
        {
            czyIstniejeAdresat = true;
            wybor = AuxiliaryMethods::choseOptionFromEditionMenu();

            switch (wybor)
            {
            case '1':
                cout << "Podaj nowe imie: ";
                recipients[i].setName(AuxiliaryMethods::loadALine());
                recipients[i].setName(replaceFirstLetterToUppercaseAOthersToLowercase(recipients[i].getName()));
                updateDetailsOfSelectedRecipient(recipients[i], idEdytowanegoAdresata);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                recipients[i].setSurname(AuxiliaryMethods::loadALine());
                recipients[i].setSurname(replaceFirstLetterToUppercaseAOthersToLowercase(recipients[i].getSurname()));
                updateDetailsOfSelectedRecipient(recipients[i], idEdytowanegoAdresata);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                recipients[i].setPhoneNumber(AuxiliaryMethods::loadALine());
                updateDetailsOfSelectedRecipient(recipients[i], idEdytowanegoAdresata);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                recipients[i].setEmail(AuxiliaryMethods::loadALine());
                updateDetailsOfSelectedRecipient(recipients[i], idEdytowanegoAdresata);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                recipients[i].setAddress(AuxiliaryMethods::loadALine());
                updateDetailsOfSelectedRecipient(recipients[i], idEdytowanegoAdresata);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

void RecipientManager::updateDetailsOfSelectedRecipient(Recipient adresat, int idEdytowanegoAdresata)
{
    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    numerLiniiEdytowanegoAdresata = recipientFile.returnRecipientLineNumber(idEdytowanegoAdresata);
    liniaZDanymiAdresata = recipientFile.replaceRecipientDataIntoLineWithDataSeparatedByVerticalBars(adresat);
    recipientFile.editChosenLineInFile(numerLiniiEdytowanegoAdresata, liniaZDanymiAdresata);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}

void RecipientManager::searchRecipientByName()
{
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!recipients.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = AuxiliaryMethods::loadALine();
        imiePoszukiwanegoAdresata = replaceFirstLetterToUppercaseAOthersToLowercase(imiePoszukiwanegoAdresata);

        for (vector <Recipient>::iterator  itr = recipients.begin(); itr != recipients.end(); itr++)
        {
            if (itr -> getName() == imiePoszukiwanegoAdresata)
            {
                shawRecipientData(*itr);
                iloscAdresatow++;
            }
        }
        AuxiliaryMethods::displayNumberOfSearchedRecipients(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void RecipientManager::searchRecipientBySurname()
{
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    system("cls");
    if (!recipients.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = AuxiliaryMethods::loadALine();
        nazwiskoPoszukiwanegoAdresata = replaceFirstLetterToUppercaseAOthersToLowercase(nazwiskoPoszukiwanegoAdresata);

        for (vector <Recipient>::iterator itr = recipients.begin(); itr != recipients.end(); itr++)
        {
            if (itr -> getSurname() == nazwiskoPoszukiwanegoAdresata)
            {
                shawRecipientData(*itr);
                iloscAdresatow++;
            }
        }
        AuxiliaryMethods::displayNumberOfSearchedRecipients(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}
