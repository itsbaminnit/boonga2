#include <bits/stdc++.h>

struct participant {
    int completed_quest;
    int time;
    participant(int quest_, int time_) :
        completed_quest{quest_}, time{time_} {};
    void update(int quest, int time_) {
        completed_quest = quest;
        time += time_;
    }
};

std::vector<participant> _time{participant{0, 0}};



constexpr auto cmp_prtcp = [](participant& l, participant& r) {
    return l.completed_quest > r.completed_quest ? true :
           l.time > r.time ? true : false;
};

auto rdin() {
    using in_it = std::istream_iterator<char>; 
    std::string in_{};
    while(std::getline(std::cin, in_)) {
        std::istringstream ss{in_};
        int id{}, quest{}, part{}, time_{};
        auto p = std::find(in_it(ss), in_it(), '=');
        ss >> id;
        p = std::find(in_it(ss), in_it(), '=');
        ss >> quest;
        p = std::find(in_it(ss), in_it(), '=');
        ss >> part;
        p = std::find(in_it(ss), in_it(), '=');
        ss >> time_;
        std::cout << "id: " << id-- <<' '
                  << "quest: " << quest << ' '
                  << "part: " << part << ' '
                  << "time: " << time_ << '\n';
        if (id >= _time.size()) {
            auto p = _time.size();
            _time.reserve(id + 1);
            while(p < id + 1) {
                _time.emplace_back(0, 0);
                p++;
            }
        } 
        assert(id > -1);
        _time[id].update(quest, time_);
    }
    std::sort(_time.begin(), _time.end(), cmp_prtcp);
    int p{}, ans{};
    for (auto& i : _time) ans += (++p) * i.time; 
    std::cout << "total times: \n";
    constexpr auto pr = [](participant::time* p = nullptr, auto& l) { std::cout << *p(l) << ' ';};
    std::for_each(_time.begin(), _time.end(), pr);
    std::cout << "\nans: " << ans << '\n';
}

auto sol() {
    
}

auto main() -> int {
    rdin();
}
