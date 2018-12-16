import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Window 2.3
import models 1.0
import "../main/tools"

Item {
    Component {
        Header {
            id: header
        }
    }

    property Loader sign_in_loader: header.sign_in_loader
    property Loader sign_up_loader: header.sign_up_loader

    function login_required(callback, args) {
        if (User.isAuthenticated){
            return callback(args);
        } else {
            sign_in_loader.setSource("qrc:/view/user/SignIn.qml", {
                                         "loader": sign_in_loader,
                                         "second_loader": sign_up_loader
                                     })
        }
    }
}
