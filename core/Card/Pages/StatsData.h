#ifndef STATSDATA_H
#define STATSDATA_H

class PersonalData;

class StatsData
{
public:
    StatsData();

    PersonalData *personal() const;
    void setPersonal(PersonalData *personal);

private:
    PersonalData *m_personal{nullptr};
};

#endif // STATSDATA_H
