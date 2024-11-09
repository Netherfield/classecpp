

#include "ContoCorrente.hpp"

unsigned ContoCorrente::Centesimi(unsigned unità, unsigned centesimi) const {
    return unità*100 + centesimi;
}

double ContoCorrente::SaldoInLire() const {
        return saldo*cento_lire_euro;
}

void ContoCorrente::DepositaEuro(unsigned unità, unsigned centesimi) {
    // non gestisce l'overflow
    saldo += Centesimi(unità, centesimi);
}

void ContoCorrente::PrelevaEuro(unsigned unità, unsigned centesimi) {
    // non gestisce l'overdraft
    saldo -= Centesimi(unità, centesimi);
}

void ContoCorrente::AggiornaSaldo() {
    // assume tasso tra 0 e 1
    saldo = static_cast<unsigned>(saldo * (1.0 + tasso) );
}










