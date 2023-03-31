#[macro_use]
extern crate diesel;

use diesel::prelude::*;
use diesel::mysql::MysqlConnection;

fn main() {
    // let database_url = "mysql://<root>:<>@<>/<mycodedb_1>";
    let database_url = "mysql://root:/mycodedb_1";

    let connection = MysqlConnection::establish(database_url)
        .expect(&format!("Error connecting to {}", database_url));

    // Add your database operations here
}
