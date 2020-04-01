// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstddef>
#include <initializer_list>

namespace CryptoNote {
struct CheckpointData {
  uint32_t index;
  const char* blockId;
};
// ex. for block 5000 -> print_block 5001
const std::initializer_list<CheckpointData> CHECKPOINTS = {
        {0, "062d22e5e52f0d24b4a72ab53df4cbb9ef780b63be689095a620a218cc31fea3"},
        {2, "e195038d9734112d6aafeb229b03c5a0d204296012f3924947749bd7e48eafbd"},
        {5000, "944546744425404fc09cea58fd47e299f6f503bcddcc03e043b1782244bc7e99"},
        {10000, "65d832f29457f9e9124b4e7b7309164b271c9e12f94ed1fcea4ae503f76cd265"},
        {15000, "30bfe7f3bab1b40711488b70bf6657e5086f49df4067020184aa5f5e9601a8fd"},
        {20000, "189ce0d323dd00235a9cb534bab4d99508ff165f7d7baabf00f2ff058454d306"},
        {25000, "dcc6aadf6e67c0694dc888eb7f46b3fc023c4cd2aed9d9cd73b9a6935b3d46a8"},
        {30000, "7e9fe521da80d55b2bc845ec50524c65fed2bf379f7863b72fb7433c6082546d"},
        {35000, "9fd05971f57f4b2bfbb757719beda00fb421c728169636da1560271320f4dcde"},
        {40000, "93754b0d02030287925db010421c3ebe20e2976f5aadb7cb504f5508a8b6669f"},
        {45000, "0579738899a472c1dac585fc5b6de4c0153cfde9fc8cff6ef0adcdb500dacd34"},
        {50000, "4e2ae83793e8024b9d7df9f0d923f7d93848d8a25b4c68c7823ba79b13b748f3"},
        {55000, "e40a1c980d884fb8296f7e8ca20fbcf21ab44ccaebcf37bdb58b8547a1856643"},
        {60000, "8e0d27ac9c64173053dc0536ea872e6a63639b7d7b7a062b10076e5452db1e95"},
        {65000, "8096eed42c5f413e7ef68bfa38108c422c21018eb8cda5450a003390153d2cd3"},
        {70000, "eac2e8f04fd8bd6143f00013400f9672399ec3137701ef4c27e48a4f850efca1"},
        {75000, "e0619957c3299a799cf1ebc9e1d344857a217f9712e643148a45979675ad649f"},
        {80000, "61478707645cf09ed45d11d20ddd1a52dc2234ab2ca6c72f4fa18fa389a470eb"},
        {85000, "3193c91ed4102561b011c96e1d9d80109712d2a01d7526b1be4e04ea084e6585"},
        {90000, "e900a6a309d18ed304240ca6d572a6bc536e767f452fb7dafff93dd60212ea2c"},
        {95000, "a614b5ad4d6c831cb01aadfebc5a2de1ef7d617cf65028c3a4130e56dcc0767e"},
        {100000, "691373268932d3e3dc3de3a0a747a6a1e772a1ee2f740faeba1266ad7e2dbe17"},
        {105000, "fd4c8fedd7980272b406844a365b861063332075d74edc374293fb448919133a"},
        {110000, "7f36ea38b85bf837350d41f8c0cf408e51a8c34413688bf12560b96edecd54e9"},
        {115000, "3522ed8338a4e59752e615f64bf1b39e85a514da8544f1b0efbbd30672222908"},
        {120000, "64218c4be4544ffd8e0184dc367512e46c26fe343b8e21a5165fbfa28ca72950"},
        {125000, "1a56d44a1563ec7b6ec0e2ec109310ddc3e32e14252be38e003bc59f4d6e7106"},
        {130000, "1b1b133ea2000dee9e776f94dff25fa99a39bc4deaab97e7c59501bf181b1a8b"},
        {135000, "0c0dbce1535a3938f8716efc03a7de43f4ef5d5afbdd5fe948efefd6eb0c5777"},
        {140000, "a000736ec4280e007f9e42d0d1ffcb55c4b9522879ad11fa5ea42276b069625c"},
        {145000, "47518e2424fe921cd305c2aa32c3477086ee1cbb7cde69a5c168f292ef346732"},
        {150000, "a79b5deb065806a11551a61f48a8ffcc460c9b8b0d7cad736447a75ea350cd75"},
        {155000, "f7fa217477e9d9b3c3cd34eb1fd06dd533cebfe9b82910d6ae5d8385954a2573"},
        {160000, "14a0eb610b928cfa5c2034884ea238aeaf3bb02738daa8b2a140032f0794f64c"},
        {165000, "da993e58b1394d0d1af0bb1ca10f20797d732b3b7556fe57956ea7524aab13f6"},
        {170000, "13514b53d498a0c2f0672e9cff0e780ea7c91aad2224b488bcafc3978556b1bf"}
};
}
