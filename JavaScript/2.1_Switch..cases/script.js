let user = 'admin';

switch(user){
    case 'admin':
        console.log('login as admin');
        break;

    case 'guest':
        console.log('login as guest');
        break;

    default:
        console.log('unknown user');
}