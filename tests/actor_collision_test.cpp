#include "actor.h"

#include "catch.hpp"

#include <map>
#include <set>
#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>


using namespace SDL2pp;

class TestActor : public Actor
{
public:
    TestActor(SDL2pp::Rect boundingBox) : m_bb(boundingBox) {}

    virtual SDL2pp::Texture& getTexture() const override
    {
        return *m_tex;
    }

    virtual SDL2pp::Point getPos() const override
    {
        return {};
    }

    virtual SDL2pp::Rect getBoundingBox() const override
    {
        return m_bb;
    }

private:
    SDL2pp::Rect m_bb;
    std::shared_ptr<SDL2pp::Texture> m_tex;
};

template <typename ContainerT>
std::map<ActorPtr, std::set<ActorPtr>> collisions(const ContainerT& actors)
{
    std::map<ActorPtr, std::set<ActorPtr>> results;

    for (const ActorPtr& actorA : actors)
    {
        for (const ActorPtr& actorB : actors)
        {
            if (actorA != actorB)
            {
                auto intersects = actorA->getBoundingBox().Intersects(actorB->getBoundingBox());
                if (intersects)
                {
                    results[actorA].insert(actorB);
                }
            }
        }
    }

    return results;
}

template <typename DataT, typename ContainerT>
bool contains(const ContainerT& container, const DataT& value)
{
    return std::find(std::begin(container), std::end(container), value) != std::end(container);
}

TEST_CASE("TestActorCollision") {

    auto a = std::make_shared<TestActor>(Rect{1,2,3,4});
    auto b = std::make_shared<TestActor>(Rect{1,2,3,4});
    auto c = std::make_shared<TestActor>(Rect{1,2,3,4});
    auto d = std::make_shared<TestActor>(Rect{100,100,3,4});

    auto col = collisions(std::vector<ActorPtr>{a,b,c,d});

    REQUIRE(col.size() == 3);
    REQUIRE(col[a].size() == 2);
    REQUIRE(col[b].size() == 2);
    REQUIRE(col[c].size() == 2);

    REQUIRE(!contains(col[a], a));
    REQUIRE(contains(col[a], b));
    REQUIRE(contains(col[a], c));

    REQUIRE(contains(col[b], a));
    REQUIRE(!contains(col[b], b));
    REQUIRE(contains(col[b], c));

    REQUIRE(contains(col[c], a));
    REQUIRE(contains(col[c], b));
    REQUIRE(!contains(col[c], c));
}
