/*-
 * Copyright (c) 2014-2020 MongoDB, Inc.
 * Copyright (c) 2008-2014 WiredTiger, Inc.
 *  All rights reserved.
 *
 * See the file LICENSE for redistribution information.
 */

#pragma once

#include "wiredtiger.h"

namespace wt {

static const std::string get_error_message(int return_code) {
    return wiredtiger_strerror(return_code);
}

static int create_table(
  WT_SESSION *session, const std::string &uri, const std::string &config) {
    return session->create(session, uri.c_str(), config.c_str());
}

static int close_database(WT_CONNECTION *conn) {
    return conn->close(conn, nullptr);
}

static int close_cursor(WT_CURSOR *cursor) {
    return cursor->close(cursor);
}

int open_cursor(WT_SESSION *session,
                const std::string &uri,
                WT_CURSOR **cursorp);

int open_database(const std::string &path,
                  WT_CONNECTION **connp,
                  WT_SESSION **sessionp);

int create_table(WT_SESSION *session,
                 const std::string &uri,
                 const std::string &config);

int row_table_insert(WT_CURSOR *cursor,
                     uint64_t document_id,
                     const std::string &key,
                     uint16_t type,
                     WT_ITEM item);

int col_table_insert(WT_CURSOR *cursor,
                     const std::string &key,
                     uint64_t document_id,
                     uint16_t type,
                     WT_ITEM item);

int row_table_print(WT_SESSION *session,
                    const std::string &uri);

int col_table_print(WT_SESSION *session,
                    const std::string &uri);

} // namespace wt