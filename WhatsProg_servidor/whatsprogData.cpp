#include "whatsprogData.h"

bool Message::setId(uint32_t I){
    if (I<=0){
        id = 0;
        return false;
    }

    id=I;
    return true;
}

bool Message::setSender(const string &R){
    if (R.size()<SIZE_MIN_LOGIN_USER || R.size()>SIZE_MAX_LOGIN_USER){
        sender = "";
        return false;
    }
    sender=R;
    return true;
}

bool Message::setReceiver(const string &D){
    if (D.size()<SIZE_MIN_LOGIN_USER || D.size()>SIZE_MAX_LOGIN_USER){
        receiver = "";
        return false;
    }
    receiver = D;
    return true;
}

bool Message::setText(const string &T){
    if (T.size()==0 || T.size() > 255){
        text = "";
        return false;
    }
    text=T;
    return true;
}

bool Message::setStatus(MsgStatus S){
    if (S!=MSG_ENVIADA && S!=MSG_RECEBIDA && S!=MSG_ENTREGUE && S!=MSG_LIDA && S!=MSG_INVALIDA){
        status = MSG_INVALIDA;
        return false;
    }
    status=S;
    return true;
}